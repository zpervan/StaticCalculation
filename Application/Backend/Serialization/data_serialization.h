#ifndef STATICCALCULATION_DATA_SERIALIZATION_H
#define STATICCALCULATION_DATA_SERIALIZATION_H

#include <string>

#include "Application/Backend/Serialization/Messages/data.pb.h"

namespace Backend
{

/// @brief Save the data to a default location, i.e C:\Documents\StatikaTorzo
inline void Save()
{
    /// @TODO: Save data to file
}

/// @brief Save the data to a specific path.
/// @param path Location where the data should be saved
inline void SaveOnPath([[maybe_unused]] const std::string & path)
{
    /// @TODO: Save data to file on specific path
}

/// @brief Load saved data from a specific path.
/// @param path Saved file location
inline void Load([[maybe_unused]]const std::string& path)
{
    /// @TODO: Load data from file
}

}

#endif  // STATICCALCULATION_DATA_SERIALIZATION_H
