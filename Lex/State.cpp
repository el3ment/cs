#include "State.h"

using namespace std;

string StateToString(State tokenType){
    string result = "";
    switch(tokenType){
        case Comma:                      result = "Comma"; break;
        case Period:                     result = "Period"; break;
        case SawColon:                   result = "SawColon"; break;
        case Colon_Dash:                 result = "Colon_Dash"; break;
        case SawAQuote:                  result = "SawAQuote"; break;
        case ProcessingString:           result = "ProcessingString"; break;
        case PossibleEndOfString:        result = "PossibleEndOfString"; break;
        case Start:                      result = "Start"; break;
        case End:                        result = "End"; break;
        case SawComment:		 result = "SawComment"; break;
        case ProcessingComment:		 result = "ProcessingComment"; break;
        case PossibleEndOfComment:	 result = "PossibleEndOfComment"; break;
        case ProcessingBlockComment:	 result = "ProcessingBlockComment"; break;
        case Id:			 result = "Id"; break;
        case Keyword:			 result = "StartKeyword"; break;
        case Whitespace:		 result = "Whitespace"; break;
        case EndOfFile:			 result = "EndOfFile"; break;
        case Undefined:			 result = "Unknown"; break;

        case Q_Mark:			 result = "Q_Mark"; break;
        case Left_Paren:		 result = "Left_Paren"; break;
        case Right_Paren:		 result = "Right_Paren"; break;
        case Multiply:			 result = "Multiply"; break;
        case Add:			 result = "Add"; break;
		
    }
    return result;
};
