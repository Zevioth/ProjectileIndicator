#include <pl/Mod.hpp>

namespace projectile_indicator {

class ProjectileIndicatorMod {
public:
    static ProjectileIndicatorMod& instance() {
        static ProjectileIndicatorMod mod;
        return mod;
    }

    ProjectileIndicatorMod()
        : mSelf(*ll::mod::NativeMod::current()) {}

    bool load() {
        mSelf.getLogger().info("Projectile Indicator: native module loaded (phase 0)");
        mSelf.getLogger().info("Next milestone: verify game-version hooks, then trajectory rendering");
        return true;
    }

    bool enable() {
        mSelf.getLogger().info("Projectile Indicator enabled");
        return true;
    }

    bool disable() {
        mSelf.getLogger().info("Projectile Indicator disabled");
        return true;
    }

    bool unload() {
        mSelf.getLogger().info("Projectile Indicator unloaded");
        return true;
    }

private:
    ll::mod::NativeMod& mSelf;
};

} // namespace projectile_indicator

PL_REGISTER_MOD(projectile_indicator::ProjectileIndicatorMod,
                projectile_indicator::ProjectileIndicatorMod::instance())
