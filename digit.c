/**********************************************************************
 * Libraries
***********************************************************************/
#include <stdio.h>



/**********************************************************************
 * Predefined functions: Call these functions in your code to get user
 *                       input and report information to the user.
 *                       Do not modify these functions.
***********************************************************************/

// Asks the user for a number and returns that number        
long get_input() {
    long input;
    printf(" Enter a non-negative number (of at most 18 digits): ");
    scanf("%ld",&input);
    return input;
}

// Prints the final output
void print_output(int highest_digit) {
    printf(" The highest digit in the number is %d.\n", highest_digit);
}



/**********************************************************************
 * Main functionality: Write your code for finding the highest 
 *                     digit below.
***********************************************************************/
long digits(long n){
	long max = 0;
	while(n>0){
		long digit = n % 10;
		if(digit > max)
			max = digit;
		n = n/10;
	}
	return max;
}

int main(){
	long userResponse = get_input();
	long max = digits(userResponse);
	print_output(max);
}
