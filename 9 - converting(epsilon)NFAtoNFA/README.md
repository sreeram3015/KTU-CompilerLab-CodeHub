# Algorithm:

Input Alphabets:
Read the number of alphabets (numAlphabets).
Read the alphabets (alphabets).

Input States:
Read the number of states (numStates).
Read the start state (startState).
Read the number of final states (numFinalStates).
Read the final states (finalStates).

Input Transitions:
Read the number of transitions (numTransitions).
Read each transition in the form: currentState alphabet nextState.
Insert each transition into the transition table (transitionTable).

Epsilon Closure:
For each state, find the epsilon closure by recursively exploring epsilon transitions.
Store the epsilon closure in epsilonClosure array.

Print Equivalent NFA without Epsilon:
Print start state, alphabets, and states without epsilon closure.
For each state, print transitions without epsilon.

Find and Print Final States:
Find and print final states by matching with epsilon closures.

Output:
Print the final equivalent NFA without epsilon transitions.