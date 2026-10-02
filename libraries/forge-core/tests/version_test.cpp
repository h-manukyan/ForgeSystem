#include <forge/core/version.hpp>
#include <gtest/gtest.h>

TEST(Version, IsNotEmpty) {
    EXPECT_FALSE(forge::core::version().empty());
}

TEST(Version, MatchesCurrentRelease) {
    EXPECT_EQ(forge::core::version(), "0.1.0");
}
