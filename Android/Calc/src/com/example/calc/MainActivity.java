package com.example.calc;

import android.app.Activity;
import android.content.Intent;
import android.content.res.Configuration;
import android.os.Bundle;
import android.view.Menu;
import android.view.View;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;

public class MainActivity extends Activity {
	
	TextView textView_Expr;
	TextView textView_Result;
	
	Button button_1;
	Button button_2;
	Button button_3;
	Button button_4;
	Button button_5;
	Button button_6;
	Button button_7;
	Button button_8;
	Button button_9;
	Button button_0;
	
	Button button_Add;
	Button button_Sub;
	Button button_Mul;
	Button button_Div;
	
	Button button_Equ;	
	Button button_Clr;
	Button button_Dot;
	
	private int equal_flag = 0;
	private String mathExpr = "";
	private String mathResult = "";
	private int precision = 6;
	private ScienceCalculator scienceCalculator = new ScienceCalculator();
	
	@Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);
        if (this.getResources().getConfiguration().orientation == Configuration.ORIENTATION_LANDSCAPE) {
        	Intent intent = new Intent(MainActivity.this, LandActivity.class);
            startActivity(intent);
            finish();
        }
    }
	
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        
        textView_Expr=(TextView)findViewById(R.id.textview1);
        textView_Result=(TextView)findViewById(R.id.textview2);
        
        button_1=(Button)findViewById(R.id.button1);
        button_2=(Button)findViewById(R.id.button2);
        button_3=(Button)findViewById(R.id.button3);
        button_4=(Button)findViewById(R.id.button4);
        button_5=(Button)findViewById(R.id.button5);
        button_6=(Button)findViewById(R.id.button6);
        button_7=(Button)findViewById(R.id.button7);
        button_8=(Button)findViewById(R.id.button8);
        button_9=(Button)findViewById(R.id.button9);
        button_0=(Button)findViewById(R.id.button10);
        
        button_Add=(Button)findViewById(R.id.button11);
        button_Sub=(Button)findViewById(R.id.button12);
        button_Mul=(Button)findViewById(R.id.button13);
        button_Div=(Button)findViewById(R.id.button16);
        
        button_Equ=(Button)findViewById(R.id.button17);
        button_Clr=(Button)findViewById(R.id.button14);
        button_Dot=(Button)findViewById(R.id.button15);
        
        initNumBtns();
        initBaseOpers();
        
    }
    
    

    public void initNumBtns() {

        button_0.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }

                if (mathExpr.length() == 0) {                  
                    mathExpr += "0";
                } else if (mathExpr.length() == 1) {           

                    if (mathExpr.charAt(0) == '0') {              
                        mathExpr += "";
                    } else if (isNum(mathExpr.charAt(0))) {         
                        mathExpr += "0";
                    }

                } else if (!isNum(mathExpr.charAt(mathExpr.length() - 2)) && mathExpr.charAt(mathExpr.length() - 1) == '0') {
                    mathExpr += "";                             
                } else {                                       
                    mathExpr += "0";
                }
                textView_Expr.setText(mathExpr);
            }
        });


        button_1.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }

                if (mathExpr.length() == 0) {
                    mathExpr += "1";
                } else {


                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "1";
                }
                textView_Expr.setText(mathExpr);
            }
        });

        button_2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {
                    mathExpr += "2";
                } else {
                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "2";
                }
                textView_Expr.setText(mathExpr);
            }
        });

        button_3.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {
                    mathExpr += "3";
                } else {
                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "3";
                }
                textView_Expr.setText(mathExpr);
            }
        });

        button_4.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {
                    mathExpr += "4";
                } else {
                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "4";
                }
                textView_Expr.setText(mathExpr);
            }
        });

        button_5.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {
                    mathExpr += "5";
                } else {
                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "5";
                }
                textView_Expr.setText(mathExpr);
            }
        });

        button_6.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {
                    mathExpr += "6";
                } else {
                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "6";
                }
                textView_Expr.setText(mathExpr);
            }
        });

        button_7.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {
                    mathExpr += "7";
                } else {
                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "7";
                }
                textView_Expr.setText(mathExpr);
            }
        });

        button_8.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {
                    mathExpr += "8";
                } else {
                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "8";
                }
                textView_Expr.setText(mathExpr);
            }
        });
        
        button_9.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {
                    mathExpr += "9";
                } else {
                    char ch = mathExpr.charAt(mathExpr.length() - 1);
                    if (isNum(ch) || isOper(ch) || ch == '(' || ch == '.')
                        mathExpr += "9";
                }
                textView_Expr.setText(mathExpr);
            }
        });

        button_Dot.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (equal_flag == 1) {
                    mathExpr = "";
                    equal_flag = 0;
                }
                if (mathExpr.length() == 0) {                               
                    mathExpr += "0.";
                } else if (isOper(mathExpr.charAt(mathExpr.length() - 1))) { 
                    mathExpr += "0.";
                } else if (isNum(mathExpr.charAt(mathExpr.length() - 1))) {  
                    mathExpr += ".";
                } else {                                                  
                    mathExpr += "";
                }
                textView_Expr.setText(mathExpr);
            }
        });
    }
    
    
    public void initBaseOpers() {

        button_Add.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mathExpr.length() == 0) {
                    mathExpr += "+";
                } else {
                    if (isNum(mathExpr.charAt(mathExpr.length() - 1))
                            || mathExpr.charAt(mathExpr.length() - 1) == ')'
                            || mathExpr.charAt(mathExpr.length() - 1) == '('
                            || mathExpr.charAt(mathExpr.length() - 1) == 'e')
                        mathExpr += "+";
                }
                textView_Expr.setText(mathExpr);
                equal_flag = 0; 
            }
        });

        button_Sub.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mathExpr.length() == 0) {
                    mathExpr += "-";
                } else {
                    if (isNum(mathExpr.charAt(mathExpr.length() - 1))
                            || mathExpr.charAt(mathExpr.length() - 1) == ')'
                            || mathExpr.charAt(mathExpr.length() - 1) == '('
                            || mathExpr.charAt(mathExpr.length() - 1) == 'e')
                        mathExpr += "-";
                }
                textView_Expr.setText(mathExpr);
                equal_flag = 0;
            }
        });

        button_Mul.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mathExpr.length() != 0) {
                    if (isNum(mathExpr.charAt(mathExpr.length() - 1))
                            || mathExpr.charAt(mathExpr.length() - 1) == ')'
                            || mathExpr.charAt(mathExpr.length() - 1) == 'e')
                        mathExpr += "¡Á";
                }
                textView_Expr.setText(mathExpr);
                equal_flag = 0;
            }
        });

        button_Div.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (mathExpr.length() != 0) {
                    if (isNum(mathExpr.charAt(mathExpr.length() - 1))
                            || mathExpr.charAt(mathExpr.length() - 1) == ')'
                            || mathExpr.charAt(mathExpr.length() - 1) == 'e')
                        mathExpr += "/";
                }
                textView_Expr.setText(mathExpr);
                equal_flag = 0;
            }
        });
        
        button_Equ.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {

               
                double result = scienceCalculator.cal(mathExpr, precision, 0); 

                if (result == Double.MAX_VALUE)
                    mathExpr = "Math Error";
                else {
                    mathExpr = String.valueOf(result);
                    if (mathExpr.charAt(mathExpr.length() - 2) == '.' && mathExpr.charAt(mathExpr.length() - 1) == '0') {
                        mathExpr = mathExpr.substring(0, mathExpr.length() - 2);
                    }
                }
                mathResult=mathExpr;
                textView_Result.setText(mathResult);

               
                equal_flag = 1; 
            }
        });
        
        button_Clr.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                mathExpr = "";
                mathResult = "";
                textView_Expr.setText(mathExpr);
                textView_Result.setText(mathResult);
                Toast.makeText(MainActivity.this, "Clear", Toast.LENGTH_SHORT).show();
            }
        });
    }
    
    

    

    private boolean isNum(char c) {
        char num[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
        int i = 0;
        for (; i < num.length; i++) {
            if (num[i] == c)
                break;
        }
        return i != num.length;
    }


    private boolean isOper(char c) {
        char oper[] = {'+', '-', '¡Á', '/'};
        int i = 0;
        for (; i < oper.length; i++) {
            if (oper[i] == c)
                break;
        }
        return i != oper.length;
    }


    private boolean hasLeftBracket(String s) {
        int i = 0;
        for (; i < s.length(); i++) {
            if (s.charAt(i) == '(')
                break;
        }
        return i != s.length();
    }

    

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        // Inflate the menu; this adds items to the action bar if it is present.
        getMenuInflater().inflate(R.menu.main, menu);

        return true;
    }
    
}
