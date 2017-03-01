// Copyright (c) 2013-2015 Vittorio Romeo
// License: Academic Free License ("AFL") v. 3.0
// AFL License page: http://opensource.org/licenses/AFL-3.0

#ifndef SSVSC_BODY_GROUPABLE
#define SSVSC_BODY_GROUPABLE

namespace ssvsc
{
    class Groupable
    {
    private:
        GroupBitset groups, groupsToCheck, groupsNoResolve;

    public:
        inline void setGroups(bool mOn, Group mGroup) noexcept
        {
            groups[mGroup] = mOn;
        }
        inline void addGroups(Group mGroup) noexcept
        {
            setGroups(true, mGroup);
        }
        inline void delGroups(Group mGroup) noexcept
        {
            setGroups(false, mGroup);
        }
        template <typename... TGroups>
        inline void setGroups(
            bool mOn, Group mGroup, TGroups... mGroups) noexcept
        {
            setGroups(mOn, mGroup);
            setGroups(mOn, mGroups...);
        }
        template <typename... TGroups>
        inline void addGroups(Group mGroup, TGroups... mGroups) noexcept
        {
            addGroups(mGroup);
            addGroups(mGroups...);
        }
        template <typename... TGroups>
        inline void delGroups(Group mGroup, TGroups... mGroups) noexcept
        {
            delGroups(mGroup);
            delGroups(mGroups...);
        }

        inline void setGroupsToCheck(bool mOn, Group mGroup) noexcept
        {
            groupsToCheck[mGroup] = mOn;
        }
        inline void addGroupsToCheck(Group mGroup) noexcept
        {
            setGroupsToCheck(true, mGroup);
        }
        inline void delGroupsToCheck(Group mGroup) noexcept
        {
            setGroupsToCheck(false, mGroup);
        }
        template <typename... TGroups>
        inline void setGroupsToCheck(
            bool mOn, Group mGroup, TGroups... mGroups) noexcept
        {
            setGroupsToCheck(mOn, mGroup);
            setGroupsToCheck(mOn, mGroups...);
        }
        template <typename... TGroups>
        inline void addGroupsToCheck(Group mGroup, TGroups... mGroups) noexcept
        {
            addGroupsToCheck(mGroup);
            addGroupsToCheck(mGroups...);
        }
        template <typename... TGroups>
        inline void delGroupsToCheck(Group mGroup, TGroups... mGroups) noexcept
        {
            delGroupsToCheck(mGroup);
            delGroupsToCheck(mGroups...);
        }

        inline void setGroupsNoResolve(bool mOn, Group mGroup) noexcept
        {
            groupsNoResolve[mGroup] = mOn;
        }
        inline void addGroupsNoResolve(Group mGroup) noexcept
        {
            setGroupsNoResolve(true, mGroup);
        }
        inline void delGroupsNoResolve(Group mGroup) noexcept
        {
            setGroupsNoResolve(false, mGroup);
        }
        template <typename... TGroups>
        inline void setGroupsNoResolve(
            bool mOn, Group mGroup, TGroups... mGroups) noexcept
        {
            setGroupsNoResolve(mOn, mGroup);
            setGroupsNoResolve(mOn, mGroups...);
        }
        template <typename... TGroups>
        inline void addGroupsNoResolve(
            Group mGroup, TGroups... mGroups) noexcept
        {
            addGroupsNoResolve(mGroup);
            addGroupsNoResolve(mGroups...);
        }
        template <typename... TGroups>
        inline void delGroupsNoResolve(
            Group mGroup, TGroups... mGroups) noexcept
        {
            delGroupsNoResolve(mGroup);
            delGroupsNoResolve(mGroups...);
        }

        inline void clearGroups() noexcept { groups.reset(); }
        inline void clearGroupsToCheck() noexcept { groupsToCheck.reset(); }
        inline void clearGroupsNoResolve() noexcept { groupsNoResolve.reset(); }

        inline constexpr bool hasGroup(Group mGroup) const noexcept
        {
            return groups[mGroup];
        }
        inline constexpr bool hasGroupToCheck(Group mGroup) const noexcept
        {
            return groupsToCheck[mGroup];
        }
        inline constexpr bool hasGroupNoResolve(Group mGroup) const noexcept
        {
            return groupsNoResolve[mGroup];
        }

        inline bool hasAnyGroup(const GroupBitset& mGroups) const noexcept
        {
            return (groups & mGroups).any();
        }
        inline bool hasAnyGroupToCheck(const GroupBitset& mGroups) const
            noexcept
        {
            return (groupsToCheck & mGroups).any();
        }
        inline bool hasAnyGroupNoResolve(const GroupBitset& mGroups) const
            noexcept
        {
            return (groupsNoResolve & mGroups).any();
        }

        inline bool hasAllGroups(const GroupBitset& mGroups) const noexcept
        {
            return (groups & mGroups).all();
        }
        inline bool hasAllGroupsToCheck(const GroupBitset& mGroups) const
            noexcept
        {
            return (groupsToCheck & mGroups).all();
        }
        inline bool hasAllGroupsNoResolve(const GroupBitset& mGroups) const
            noexcept
        {
            return (groupsNoResolve & mGroups).all();
        }

        inline const auto& getGroups() const noexcept { return groups; }
        inline const auto& getGroupsToCheck() const noexcept
        {
            return groupsToCheck;
        }
        inline const auto& getGroupsNoResolve() const noexcept
        {
            return groupsNoResolve;
        }
    };
}

#endif
