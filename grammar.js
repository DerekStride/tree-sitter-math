module.exports = grammar({
  name: 'math',

  rules: {
    expression: $ => $._expression,
    _expression: $ => choice(
      $.variable,
      $.number,
      $.sum,
    ),

    sum: $ => prec.left(
      seq(
        field("left", $._expression),
        "+",
        field("right", $._expression),
      ),
    ),

    number: _ => /\d+(\.\d+)?/,
    variable: _ => /([a-zA-Z$][0-9a-zA-Z_]*)/,
  }
});
