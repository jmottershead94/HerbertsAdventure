// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVSC_SPATIAL_GRID_CELL
#define SSVSC_SPATIAL_GRID_CELL

namespace ssvsc
{
    template <typename TW>
    class Cell
    {
    public:
        using BaseType = Base<TW>;
        using BodyType = Body<TW>;

    private:
        std::vector<BodyType*> bodies;

    public:
        inline void add(BaseType* mBase, BodyTag)
        {
            SSVU_ASSERT(mBase != nullptr);
            bodies.emplace_back(ssvu::castUp<BodyType>(mBase));
        }
        inline void del(BaseType* mBase, BodyTag)
        {
            SSVU_ASSERT(mBase != nullptr);
            ssvu::eraseRemove(bodies, ssvu::castUp<BodyType>(mBase));
        }
        inline void add(BaseType*, SensorTag) {}
        inline void del(BaseType*, SensorTag) {}

        inline const auto& getBodies() const noexcept { return bodies; }
    };
}

#endif
