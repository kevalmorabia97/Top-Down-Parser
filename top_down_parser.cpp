#include<bits/stdc++.h>
using namespace std;

void print_stack(stack<char> &s){
    if(s.empty()) {
        return;
    }
    char x = s.top();
    s.pop();
    print_stack(s);
    s.push(x);
    cout << x << " ";
}

int check_if_valid(string input, string rules[], int no_rules, char start_non_term){
	//cout << input << endl;
	stack<char> s;
	s.push('$');
	s.push(start_non_term);
	int index=0;
	char curr = input[index];
	index++;
	while(1){
		cout << "curr_sym:" << curr << ", ";
		cout << "Stack: ";
		print_stack(s);
		cout << endl;
		if(s.top()=='$')	break;
		if(s.top()==curr){
			s.pop();
			curr = input[index];
			index++;
			continue;
		}
		char non_term = s.top();
		int rule_found = 0;
		vector<string> useful_rules;
		for(int i = 0; i < no_rules; i++){
			if(rules[i][0]==non_term)	useful_rules.push_back(rules[i]);
		}
		if(useful_rules.size()==0)	return 0;
		if(useful_rules.size()==1){
			s.pop();
			if(useful_rules[0][1]!='e'){
				for(int j = useful_rules[0].length()-1; j>0; j--){
					s.push(useful_rules[0][j]);
				}
			}
			rule_found = 1;
		}else{
			int can_give_null = 0; // null production possible
			for(int i = 0; i < useful_rules.size(); i++){
				if(useful_rules[i][1]==curr){
					s.pop();
					for(int j = useful_rules[0].length()-1; j>0; j--){
						s.push(useful_rules[i][j]);
					}
					rule_found = 1;
					break;
				}else if(useful_rules[i][1]=='e')	can_give_null = 1;
			}
			if(!rule_found && can_give_null){
				s.pop();
				rule_found = 1;
			}
		}
		if(!rule_found)	return 0;
	}
	if(s.top()=='$' && index==input.length())	return 1;
	else return 0;
}

int main(){
    int no_rules;
    cout << "Enter number of rules:";
    cin >> no_rules;
    
    string rules[no_rules];
    cout << "\nEnter rules in the form AB+C meaning A->B+C\n";
    for(int i = 0; i < no_rules; i++)	cin >> rules[i];
    
    char start_non_term;
    cout << "\nEnter starting non terminal:";
    cin >> start_non_term;
    
    string input;
    cout << "\nEnter input ending with $:";
   	cin >> input;
   	
   	cout << check_if_valid(input, rules, no_rules, start_non_term) << endl;
    return 0;
}

/*
EXAMPLE:
----------
RULES (18)
E -> TA
A -> +TA|-TA|e
T -> FB
B -> *FB|/FB|e
F -> 0|1|...|9

ETA
A+TA
A-TA
Ae
TFB
B*FB
B/FB
Be
F0
F1
F2
F3
F4
F5
F6
F7
F8
F9
*/
