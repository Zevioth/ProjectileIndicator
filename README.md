# Projectile Indicator — LeviLaunchroid Android starter

This is the **Android LeviLauncher / LeviLaunchroid** project, not the separate Windows LeviLauncher + LeviLamina project.

## What this starter does

- Uses the official `LiteLDev/preloader-android` SDK (tag `0.2.3`).
- Targets `arm64-v8a` for Android Bedrock.
- Registers a native mod lifecycle and writes load/enable/disable/unload messages to the mod logger.
- Uses GitHub Actions to build and package a `.levipack`, so you can work from your Android phone without compiling C++ locally.

**This is phase 0 only. It does not draw a trajectory yet.** First we need a clean module that builds and loads. Trajectory prediction/rendering will be the next milestone and must be tested against the exact Minecraft version you use.

## Build from your phone using GitHub Actions

1. Download and extract this ZIP.
2. In GitHub, create a new public or private repository named `ProjectileIndicator`.
3. Use the repository's **Add file → Upload files** page in your phone browser to upload the *contents* of this folder (including the hidden `.github` folder and `.github/workflows/build.yml`). If the GitHub mobile view hides dot-folders or makes upload awkward, open the page's browser menu and choose **Desktop site**.
4. Commit the files to `main` (or `master`).
5. Open the repository's **Actions** tab and select **Build Android LeviLauncher mod**. It should run automatically on the first push; you can also press **Run workflow**.
6. Open the completed run and download the `ProjectileIndicator-levipack` artifact.
7. Import `ProjectileIndicator.levipack` in the Android LeviLauncher/LeviLaunchroid mod import UI.

## Build locally later

The documented SDK setup uses CMake, the Android NDK, and Preloader Android. The workflow in `.github/workflows/build.yml` installs the NDK in a GitHub-hosted runner and builds the `arm64-v8a` library.

## Important limitations

- Not yet a projectile predictor; only the native module lifecycle exists.
- Rendering a 3D path and getting camera/world/collision data require version-specific integration. We'll implement those after this module successfully loads.
- Empty `minecraft_versions` in the manifest lets the launcher consider all versions, but it does **not** prove the internal game hooks are compatible with all versions.
- Back up your Minecraft worlds before testing native mods.

## Official references

- LeviLaunchroid: https://github.com/LiteLDev/LeviLaunchroid
- Android native mod quick start: https://levilaunchroid.levimc.org/guide/developer
- Preloader Android SDK: https://github.com/LiteLDev/preloader-android
