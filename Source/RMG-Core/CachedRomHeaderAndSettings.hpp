/*
 * Rosalie's Mupen GUI - https://github.com/Rosalie241/RMG
 *  Copyright (C) 2020 Rosalie Wanders <rosalie@mailbox.org>
 *
 *  This program is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License version 3.
 *  You should have received a copy of the GNU General Public License
 *  along with this program. If not, see <https://www.gnu.org/licenses/>.
 */
#ifndef CORE_CACHEDROMHEADERANDSETTINGS_HPP
#define CORE_CACHEDROMHEADERANDSETTINGS_HPP

#include <filesystem>

#include "RomHeader.hpp"
#include "RomSettings.hpp"

#ifdef CORE_INTERNAL
// attempts to read rom header & settings cache
void CoreReadRomHeaderAndSettingsCache(void);

// returns whether saving the rom header & settings cache
// succeeds
bool CoreSaveRomHeaderAndSettingsCache(void);
#endif // CORE_INTERNAL

// returns whether rom header & settings have been cached
// for given filename
bool CoreHasRomHeaderAndSettingsCached(std::filesystem::path file);

// returns whether retrieving the rom header & settings
// for given filename succeeds
bool CoreGetCachedRomHeaderAndSettings(std::filesystem::path file, CoreRomHeader& header, CoreRomSettings& settings);

// returns whether adding cached rom header & settings
// for given filename succeeds
bool CoreAddCachedRomHeaderAndSettings(std::filesystem::path file, CoreRomHeader header, CoreRomSettings settings);

#endif // CORE_CACHEDROMHEADERANDSETTINGS_HPP
