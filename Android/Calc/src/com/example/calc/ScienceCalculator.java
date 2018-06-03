package com.example.calc;

import java.math.BigDecimal;

import android.R.integer;
import android.renderscript.Element;

class ScienceCalculator {

    private BaseCalculator baseCalculator = new BaseCalculator();

    double cal(String math, int precision, int angle_metric) {


        math = math.replace(" ", "");                             
        math = math.replace("e", String.valueOf(Math.exp(1)));     


        while (math.contains("^")) {


            int midIndex = math.lastIndexOf("^");


            double leftNum; 
            String leftStr; 
            int leftIndex = midIndex - 1;

            if (math.charAt(leftIndex) == ')') {        
                int i = leftIndex - 1;
                while (math.charAt(i) != '(') {
                    i--;
                }
                String subLeftMath = math.substring(i + 1, leftIndex);
                leftNum = baseCalculator.cal(subLeftMath);
                if (leftNum == Double.MAX_VALUE) 
                    return Double.MAX_VALUE;

                leftStr = "(" + subLeftMath + ")";
            } else {                                   

                while (leftIndex >= 0 && !isOper(math.charAt(leftIndex))) {
                    leftIndex--;
                }
                leftStr = math.substring(leftIndex + 1, midIndex);
                leftNum = Double.parseDouble(leftStr);
            }

            double rightNum;
            String rightStr;
            int rightIndex = midIndex + 1;

            if (math.charAt(rightIndex) == '(') {
                int i = rightIndex + 1;
                while (math.charAt(i) != ')') {
                    i++;
                }
                String subRightMath = math.substring(rightIndex + 1, i);
                rightNum = baseCalculator.cal(subRightMath);
                if (rightNum == Double.MAX_VALUE)
                    return Double.MAX_VALUE;
                rightStr = "(" + subRightMath + ")";
            } else {
                while (rightIndex < math.length() && !isOper(math.charAt(rightIndex))) {
                    rightIndex++;
                }
                rightStr = math.substring(midIndex + 1, rightIndex);
                rightNum = Double.parseDouble(rightStr);
            }

            String wholeMath = leftStr + "^" + rightStr;
            double result = Math.pow(leftNum, rightNum);
            math = math.replace(wholeMath, String.valueOf(result));
        }

        while (math.contains("sin")
                || math.contains("cos")
                || math.contains("tan")
        		) {

            int beginIndex = math.lastIndexOf("(");
            int endIndex = getRightBracket(math, beginIndex);
            String subMath = math.substring(beginIndex + 1, endIndex);
            double subResult = baseCalculator.cal(subMath);
            if (subResult == Double.MAX_VALUE)
                return Double.MAX_VALUE;

            int i = beginIndex - 1;
            while (i >= 0 && !isOper(math.charAt(i))) { 
                i--;
            }
            String scienceOper = math.substring(i + 1, beginIndex);
            int scienceOperInt = 0;
            if(scienceOper.equals("sin"))
            	scienceOperInt=1;
            else if(scienceOper.equals("cos"))
            	scienceOperInt=2;
            else if(scienceOper.equals("tan"))
            	scienceOperInt=3;
            String tempMath;
            double tempResult;
            int DEG = 0; 
            switch (scienceOperInt) {
                case 1:
                    tempMath = "sin(" + subMath + ")";
                    if (angle_metric == DEG) {
                        tempResult = Math.sin(subResult / 180 * Math.PI); 
                    } else {
                        tempResult = Math.sin(subResult);
                    }
                    math = math.replace(tempMath, String.valueOf(tempResult));
                    break;
                case 2:
                    tempMath = "cos(" + subMath + ")";
                    if (angle_metric == DEG) {
                        tempResult = Math.cos(subResult / 180 * Math.PI);
                    } else {
                        tempResult = Math.cos(subResult);
                    }
                    math = math.replace(tempMath, String.valueOf(tempResult));
                    break;
                case 3:
                    tempMath = "tan(" + subMath + ")";
                    if (angle_metric == DEG) {
                        tempResult = Math.tan(subResult / 180 * Math.PI);
                    } else {
                        tempResult = Math.tan(subResult);
                    }
                    math = math.replace(tempMath, String.valueOf(tempResult));
                    break;
                default:
                    break;
            }
        }

        if (baseCalculator.cal(math) == Double.MAX_VALUE)
            return Double.MAX_VALUE;
        else {
            BigDecimal b = new BigDecimal(baseCalculator.cal(math));
            return b.setScale(precision, BigDecimal.ROUND_HALF_UP).doubleValue();
        }
    }

    private int getRightBracket(String math, int begin) {
        int i;
        for (i = begin; i < math.length(); i++) {
            if (math.charAt(i) == ')')
                break;
        }
        return i;
    }

    private boolean isOper(char c) {
        char[] operSet = {'+', '-', '¡Á', '/', '('};
        int i;
        for (i = 0; i < operSet.length; i++) {
            if (c == operSet[i]) {
                break;
            }
        }
        return i != operSet.length;
    }
}