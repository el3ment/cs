#ifndef STATE_H
#define STATE_H

#include <string>

/**
 * The states of the finite state machine defined in an enumerated type.
 * You will have to create additional states to assist in processing more
 * intricate input files.
 */
enum State {Comma, Period, SawColon, Colon_Dash, SawAQuote, ProcessingString,
            PossibleEndOfString, Start, End, SawComment, ProcessingComment, PossibleEndOfComment,
			ProcessingBlockComment, Id, Keyword, Whitespace, EndOfFile, Undefined, Q_Mark, Left_Paren, Right_Paren, 
			Multiply, Add};
    /**
     * Converts a state to a string.
     * 
     * Parameters: state -- the state to be converted to a string.
     * PreCondition: none
     * Postcondition: result = the string representation of the state which
     *                         looks exactly like its State name.
     */
    std::string StateToString(State state);
#endif
