module.exports = grammar({
  name: 'math',

  precedences: _ => [
    [
      "exponent",
      "multiplication",
      "addition",
    ],
  ],

  rules: {
    expression: $ => $._expression,
    _expression: $ => choice(
      $.variable,
      $.number,
      $.sum,
      $.subtraction,
      $.product,
      $.division,
      $.exponent,
      $._parenthesized_expression,
    ),

    sum: $ => prec.left(
      "addition",
      seq(
        field("left", $._expression),
        "+",
        field("right", $._expression),
      ),
    ),

    subtraction: $ => prec.left(
      "addition",
      seq(
        field("left", $._expression),
        "-",
        field("right", $._expression),
      ),
    ),

    product: $ => prec.left(
      "multiplication",
      seq(
        field("left", $._expression),
        "*",
        field("right", $._expression),
      ),
    ),

    division: $ => prec.left(
      "multiplication",
      seq(
        field("left", $._expression),
        "/",
        field("right", $._expression),
      ),
    ),

    exponent: $ => prec.left(
      "exponent",
      seq(
        field("base", $._expression),
        "**",
        field("exponent", $._expression),
      ),
    ),

    _parenthesized_expression: $ => seq(
      "(",
      $._expression,
      ")",
    ),

    number: _ => /\d+(\.\d+)?/,
    variable: _ => /([a-zA-Z$][0-9a-zA-Z_]*)/,
  }
});
