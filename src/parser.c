#include <tree_sitter/parser.h>

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wmissing-field-initializers"
#endif

#define LANGUAGE_VERSION 13
#define STATE_COUNT 10
#define LARGE_STATE_COUNT 5
#define SYMBOL_COUNT 11
#define ALIAS_COUNT 0
#define TOKEN_COUNT 6
#define EXTERNAL_TOKEN_COUNT 0
#define FIELD_COUNT 4
#define MAX_ALIAS_SEQUENCE_LENGTH 3
#define PRODUCTION_ID_COUNT 3

enum {
  anon_sym_PLUS = 1,
  anon_sym_STAR = 2,
  anon_sym_STAR_STAR = 3,
  sym_number = 4,
  sym_variable = 5,
  sym_expression = 6,
  sym__expression = 7,
  sym_sum = 8,
  sym_product = 9,
  sym_exponent = 10,
};

static const char * const ts_symbol_names[] = {
  [ts_builtin_sym_end] = "end",
  [anon_sym_PLUS] = "+",
  [anon_sym_STAR] = "*",
  [anon_sym_STAR_STAR] = "**",
  [sym_number] = "number",
  [sym_variable] = "variable",
  [sym_expression] = "expression",
  [sym__expression] = "_expression",
  [sym_sum] = "sum",
  [sym_product] = "product",
  [sym_exponent] = "exponent",
};

static const TSSymbol ts_symbol_map[] = {
  [ts_builtin_sym_end] = ts_builtin_sym_end,
  [anon_sym_PLUS] = anon_sym_PLUS,
  [anon_sym_STAR] = anon_sym_STAR,
  [anon_sym_STAR_STAR] = anon_sym_STAR_STAR,
  [sym_number] = sym_number,
  [sym_variable] = sym_variable,
  [sym_expression] = sym_expression,
  [sym__expression] = sym__expression,
  [sym_sum] = sym_sum,
  [sym_product] = sym_product,
  [sym_exponent] = sym_exponent,
};

static const TSSymbolMetadata ts_symbol_metadata[] = {
  [ts_builtin_sym_end] = {
    .visible = false,
    .named = true,
  },
  [anon_sym_PLUS] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR] = {
    .visible = true,
    .named = false,
  },
  [anon_sym_STAR_STAR] = {
    .visible = true,
    .named = false,
  },
  [sym_number] = {
    .visible = true,
    .named = true,
  },
  [sym_variable] = {
    .visible = true,
    .named = true,
  },
  [sym_expression] = {
    .visible = true,
    .named = true,
  },
  [sym__expression] = {
    .visible = false,
    .named = true,
  },
  [sym_sum] = {
    .visible = true,
    .named = true,
  },
  [sym_product] = {
    .visible = true,
    .named = true,
  },
  [sym_exponent] = {
    .visible = true,
    .named = true,
  },
};

enum {
  field_base = 1,
  field_exponent = 2,
  field_left = 3,
  field_right = 4,
};

static const char * const ts_field_names[] = {
  [0] = NULL,
  [field_base] = "base",
  [field_exponent] = "exponent",
  [field_left] = "left",
  [field_right] = "right",
};

static const TSFieldMapSlice ts_field_map_slices[PRODUCTION_ID_COUNT] = {
  [1] = {.index = 0, .length = 2},
  [2] = {.index = 2, .length = 2},
};

static const TSFieldMapEntry ts_field_map_entries[] = {
  [0] =
    {field_left, 0},
    {field_right, 2},
  [2] =
    {field_base, 0},
    {field_exponent, 2},
};

static const TSSymbol ts_alias_sequences[PRODUCTION_ID_COUNT][MAX_ALIAS_SEQUENCE_LENGTH] = {
  [0] = {0},
};

static const uint16_t ts_non_terminal_alias_map[] = {
  0,
};

static bool ts_lex(TSLexer *lexer, TSStateId state) {
  START_LEXER();
  eof = lexer->eof(lexer);
  switch (state) {
    case 0:
      if (eof) ADVANCE(2);
      if (lookahead == '*') ADVANCE(4);
      if (lookahead == '+') ADVANCE(3);
      if (lookahead == '\t' ||
          lookahead == '\n' ||
          lookahead == '\r' ||
          lookahead == ' ') SKIP(0)
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      if (lookahead == '$' ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    case 1:
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      END_STATE();
    case 2:
      ACCEPT_TOKEN(ts_builtin_sym_end);
      END_STATE();
    case 3:
      ACCEPT_TOKEN(anon_sym_PLUS);
      END_STATE();
    case 4:
      ACCEPT_TOKEN(anon_sym_STAR);
      if (lookahead == '*') ADVANCE(5);
      END_STATE();
    case 5:
      ACCEPT_TOKEN(anon_sym_STAR_STAR);
      END_STATE();
    case 6:
      ACCEPT_TOKEN(sym_number);
      if (lookahead == '.') ADVANCE(1);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(6);
      END_STATE();
    case 7:
      ACCEPT_TOKEN(sym_number);
      if (('0' <= lookahead && lookahead <= '9')) ADVANCE(7);
      END_STATE();
    case 8:
      ACCEPT_TOKEN(sym_variable);
      if (('0' <= lookahead && lookahead <= '9') ||
          ('A' <= lookahead && lookahead <= 'Z') ||
          lookahead == '_' ||
          ('a' <= lookahead && lookahead <= 'z')) ADVANCE(8);
      END_STATE();
    default:
      return false;
  }
}

static const TSLexMode ts_lex_modes[STATE_COUNT] = {
  [0] = {.lex_state = 0},
  [1] = {.lex_state = 0},
  [2] = {.lex_state = 0},
  [3] = {.lex_state = 0},
  [4] = {.lex_state = 0},
  [5] = {.lex_state = 0},
  [6] = {.lex_state = 0},
  [7] = {.lex_state = 0},
  [8] = {.lex_state = 0},
  [9] = {.lex_state = 0},
};

static const uint16_t ts_parse_table[LARGE_STATE_COUNT][SYMBOL_COUNT] = {
  [0] = {
    [ts_builtin_sym_end] = ACTIONS(1),
    [anon_sym_PLUS] = ACTIONS(1),
    [anon_sym_STAR] = ACTIONS(1),
    [anon_sym_STAR_STAR] = ACTIONS(1),
    [sym_number] = ACTIONS(1),
    [sym_variable] = ACTIONS(1),
  },
  [1] = {
    [sym_expression] = STATE(9),
    [sym__expression] = STATE(5),
    [sym_sum] = STATE(5),
    [sym_product] = STATE(5),
    [sym_exponent] = STATE(5),
    [sym_number] = ACTIONS(3),
    [sym_variable] = ACTIONS(3),
  },
  [2] = {
    [sym__expression] = STATE(6),
    [sym_sum] = STATE(6),
    [sym_product] = STATE(6),
    [sym_exponent] = STATE(6),
    [sym_number] = ACTIONS(5),
    [sym_variable] = ACTIONS(5),
  },
  [3] = {
    [sym__expression] = STATE(7),
    [sym_sum] = STATE(7),
    [sym_product] = STATE(7),
    [sym_exponent] = STATE(7),
    [sym_number] = ACTIONS(7),
    [sym_variable] = ACTIONS(7),
  },
  [4] = {
    [sym__expression] = STATE(8),
    [sym_sum] = STATE(8),
    [sym_product] = STATE(8),
    [sym_exponent] = STATE(8),
    [sym_number] = ACTIONS(9),
    [sym_variable] = ACTIONS(9),
  },
};

static const uint16_t ts_small_parse_table[] = {
  [0] = 4,
    ACTIONS(11), 1,
      ts_builtin_sym_end,
    ACTIONS(13), 1,
      anon_sym_PLUS,
    ACTIONS(15), 1,
      anon_sym_STAR,
    ACTIONS(17), 1,
      anon_sym_STAR_STAR,
  [13] = 3,
    ACTIONS(15), 1,
      anon_sym_STAR,
    ACTIONS(17), 1,
      anon_sym_STAR_STAR,
    ACTIONS(19), 2,
      ts_builtin_sym_end,
      anon_sym_PLUS,
  [24] = 3,
    ACTIONS(17), 1,
      anon_sym_STAR_STAR,
    ACTIONS(23), 1,
      anon_sym_STAR,
    ACTIONS(21), 2,
      ts_builtin_sym_end,
      anon_sym_PLUS,
  [35] = 2,
    ACTIONS(27), 1,
      anon_sym_STAR,
    ACTIONS(25), 3,
      ts_builtin_sym_end,
      anon_sym_PLUS,
      anon_sym_STAR_STAR,
  [44] = 1,
    ACTIONS(29), 1,
      ts_builtin_sym_end,
};

static const uint32_t ts_small_parse_table_map[] = {
  [SMALL_STATE(5)] = 0,
  [SMALL_STATE(6)] = 13,
  [SMALL_STATE(7)] = 24,
  [SMALL_STATE(8)] = 35,
  [SMALL_STATE(9)] = 44,
};

static const TSParseActionEntry ts_parse_actions[] = {
  [0] = {.entry = {.count = 0, .reusable = false}},
  [1] = {.entry = {.count = 1, .reusable = false}}, RECOVER(),
  [3] = {.entry = {.count = 1, .reusable = true}}, SHIFT(5),
  [5] = {.entry = {.count = 1, .reusable = true}}, SHIFT(6),
  [7] = {.entry = {.count = 1, .reusable = true}}, SHIFT(7),
  [9] = {.entry = {.count = 1, .reusable = true}}, SHIFT(8),
  [11] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_expression, 1),
  [13] = {.entry = {.count = 1, .reusable = true}}, SHIFT(2),
  [15] = {.entry = {.count = 1, .reusable = false}}, SHIFT(3),
  [17] = {.entry = {.count = 1, .reusable = true}}, SHIFT(4),
  [19] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_sum, 3, .production_id = 1),
  [21] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_product, 3, .production_id = 1),
  [23] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_product, 3, .production_id = 1),
  [25] = {.entry = {.count = 1, .reusable = true}}, REDUCE(sym_exponent, 3, .production_id = 2),
  [27] = {.entry = {.count = 1, .reusable = false}}, REDUCE(sym_exponent, 3, .production_id = 2),
  [29] = {.entry = {.count = 1, .reusable = true}},  ACCEPT_INPUT(),
};

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _WIN32
#define extern __declspec(dllexport)
#endif

extern const TSLanguage *tree_sitter_math(void) {
  static const TSLanguage language = {
    .version = LANGUAGE_VERSION,
    .symbol_count = SYMBOL_COUNT,
    .alias_count = ALIAS_COUNT,
    .token_count = TOKEN_COUNT,
    .external_token_count = EXTERNAL_TOKEN_COUNT,
    .state_count = STATE_COUNT,
    .large_state_count = LARGE_STATE_COUNT,
    .production_id_count = PRODUCTION_ID_COUNT,
    .field_count = FIELD_COUNT,
    .max_alias_sequence_length = MAX_ALIAS_SEQUENCE_LENGTH,
    .parse_table = &ts_parse_table[0][0],
    .small_parse_table = ts_small_parse_table,
    .small_parse_table_map = ts_small_parse_table_map,
    .parse_actions = ts_parse_actions,
    .symbol_names = ts_symbol_names,
    .field_names = ts_field_names,
    .field_map_slices = ts_field_map_slices,
    .field_map_entries = ts_field_map_entries,
    .symbol_metadata = ts_symbol_metadata,
    .public_symbol_map = ts_symbol_map,
    .alias_map = ts_non_terminal_alias_map,
    .alias_sequences = &ts_alias_sequences[0][0],
    .lex_modes = ts_lex_modes,
    .lex_fn = ts_lex,
  };
  return &language;
}
#ifdef __cplusplus
}
#endif
