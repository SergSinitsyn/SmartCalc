#ifndef _MODEL_MODEL_H_
#define _MODEL_MODEL_H_

#include <array>
#include <cmath>
#include <cstring>
#include <exception>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>  // for scientific notation
#include <stack>
#include <string>
#include <variant>

#include "check.h"
#include "token.h"

using XYGraph = std::pair<std::vector<double>, std::vector<double>>;

class Calculator {
 public:
  Calculator(const std::string input_string);

  double CalculateValue(double x);
  double CalculateValue();

  XYGraph CalculateGraph(int number_of_points, double x_start, double x_end);

 private:
  void ConvertToPostfixNotation();

  void Parsing();
  void PushNumber(std::string temp);
  void PushToken(std::string temp);
  //   void CheckBrackets();  //!
  void UnarySigns();

  void ShuntingYardAlgorithm();
  void FromInputToOutput();
  void FromInputToStack();
  void FromStackToOutput();

  double PostfixNotationCalculation(double x);
  void ToResult();
  void ToResult(double x);
  double FromResult();

  std::string input_expression_{};
  std::map<std::string, Token> token_map_{};
  std::queue<Token> input_{};
  std::stack<Token> stack_{};
  std::queue<Token> output_{};
  std::stack<double> result_{};
};

bool is_number(char c);
bool is_symbol(char c);
bool is_letter(char c);
bool is_E(char c);
bool is_pm(char c);

#endif  // MODEL_MODEL_H_