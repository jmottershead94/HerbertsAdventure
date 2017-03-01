// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVSC_SPATIAL_GRIDINFO
#define SSVSC_SPATIAL_GRIDINFO

namespace ssvsc
{
    template <typename TW>
    class GridInfo
    {
    public:
        using SpatialType = typename TW::SpatialType;
        using BaseType = Base<TW>;
        using BodyType = Body<TW>;
        using SensorType = Sensor<TW>;
        using CellType = Cell<TW>;

    private:
        SpatialType& grid;

        // TODO: unnecessary if inheritance is used
        BaseType& base;

        std::vector<CellType*> cells;
        int startX{0}, startY{0}, endX{0}, endY{0}, oldStartX{-1},
            oldStartY{-1}, oldEndX{-1}, oldEndY{-1}, spatialPaint{-1};
        bool invalid{true};

        inline const AABB& getShapeImpl(BodyTag) const noexcept
        {
            return ssvu::castUp<BodyType>(base).getShape();
        }
        inline const AABB& getShapeImpl(SensorTag) const noexcept
        {
            return ssvu::castUp<SensorType>(base).getShape();
        }
        inline void handleCollisionImpl(FT mFT, BodyType* mBody, BodyTag) const
            noexcept
        {
            SSVU_ASSERT(mBody != nullptr);
            ssvu::castUp<BodyType>(base).handleCollision(mFT, mBody);
        }
        inline void handleCollisionImpl(
            FT mFT, BodyType* mBody, SensorTag) const noexcept
        {
            SSVU_ASSERT(mBody != nullptr);
            ssvu::castUp<SensorType>(base).handleCollision(mFT, mBody);
        }

        template <typename TTag>
        inline void calcEdges()
        {
            const auto& shape(getShapeImpl(TTag{}));

            oldStartX = startX;
            oldStartY = startY;
            oldEndX = endX;
            oldEndY = endY;

            startX = grid.getIdx(shape.getLeft());
            startY = grid.getIdx(shape.getTop());
            endX = grid.getIdx(shape.getRight());
            endY = grid.getIdx(shape.getBottom());

            if(oldStartX != startX || oldStartY != startY || oldEndX != endX ||
                oldEndY != endY)
                calcCells<TTag>();
            else
                invalid = false;
        }
        template <typename TTag>
        inline void calcCells()
        {
            clear<TTag>();

            if(!grid.isIdxValid(startX, startY, endX, endY))
            {
                base.setOutOfBounds(true);
                return;
            }
            for(int iX{startX}; iX <= endX; ++iX)
                for(int iY{startY}; iY <= endY; ++iY)
                {
                    auto& c(grid.getCell(iX, iY));
                    cells.emplace_back(&c);
                    c.add(&base, TTag{});
                }

            invalid = false;
        }
        template <typename TTag>
        inline void clear()
        {
            for(const auto& c : cells) c->del(&base, TTag{});
            cells.clear();
        }

        inline auto& getLastPaint() const noexcept
        {
            static int lastPaint{0};
            return lastPaint;
        }

    public:
        inline GridInfo(SpatialType& mGrid, BaseType& mBase) noexcept
            : grid(mGrid),
              base(mBase)
        {
        }

        template <typename TTag>
        inline void init()
        {
            calcEdges<TTag>();
            calcCells<TTag>();
        }
        inline void invalidate() noexcept { invalid = true; }
        template <typename TTag>
        inline void preUpdate()
        {
            if(invalid) calcEdges<TTag>();
        }
        inline void postUpdate() const noexcept {}
        template <typename TTag>
        inline void destroy()
        {
            clear<TTag>();
        }
        template <typename TTag>
        inline void handleCollisions(FT mFT)
        {
            ++(getLastPaint());

            for(const auto& c : cells)
                for(const auto& b : c->getBodies())
                {
                    if(b->getSpatialInfo().spatialPaint == getLastPaint())
                        continue;
                    handleCollisionImpl(mFT, b, TTag{});
                    b->getSpatialInfo().spatialPaint = getLastPaint();
                }
        }
    };
}

#endif
