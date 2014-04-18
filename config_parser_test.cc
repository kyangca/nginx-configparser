#include "gtest/gtest.h"
#include "config_parser.h"

TEST(NginxConfigParserTest, SimpleConfig) {
  NginxConfigParser parser;
  NginxConfig out_config;

  bool success = parser.Parse("example_config", &out_config);

  EXPECT_TRUE(success);
}

TEST(NginxConfigParserTest, NestedEndBlock) {
    NginxConfigParser parser;
    NginxConfig out_config;

    bool success = parser.Parse("nested_config", &out_config);
    EXPECT_TRUE(success);   
}

TEST(NginxConfigParserTest, FullNginxConfig) {
    NginxConfigParser parser;
    NginxConfig out_config;

    bool success = parser.Parse("full_nginx_config", &out_config);
    EXPECT_TRUE(success);
}

TEST(NginxConfigParserTest, DoubleEndStatement) {
    NginxConfigParser parser;
    NginxConfig out_config;

    bool success = parser.Parse("double_end_config", &out_config);
    EXPECT_FALSE(success);
}

TEST(NginxConfigParserTest, NoEndStatementBeforeEOF) {
    NginxConfigParser parser;
    NginxConfig out_config;

    bool success = parser.Parse("no_end_config", &out_config);
    EXPECT_FALSE(success);
}

TEST(NginxConfigParserTest, CommentInToken) {
    NginxConfigParser parser;
    NginxConfig out_config;

    bool success = parser.Parse("hashtag_config", &out_config);
    EXPECT_FALSE(success);
}
