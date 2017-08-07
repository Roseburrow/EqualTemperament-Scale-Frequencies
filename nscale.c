/*Prints out the notes of a scale of N-notes of equal temperament starting from
  a given midi note*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(int argc, char* argv[])
{
    int notes_per_octave, starting_midi, i;
    double ratio, c0, c5, freq;
    double scale[24];

    //Validate input arguments...
    if (argc != 3)
    {
	printf("Incorrect Use of Program!\nUse: %s notes startmidi\n", argv[0]);
	return 1;
    }
    
    notes_per_octave = atoi(argv[1]);

    if (notes_per_octave < 1 || notes_per_octave > 24)
    {
	printf("Please make sure that the number of note per octave is between"
	       " 1-24\n");
	return 1;
    }

    starting_midi = atoi(argv[2]);

    if (starting_midi < 0 || starting_midi > 127)
    {
	printf("Please enter a valid midi note between 0-127\n");
	return 1;
    }
    
    ratio = pow(2.0, 1.0 / 12.0);
    printf("Semitone Ratio: %lf\n\n", ratio);
    
    c5 = 220.0 * pow(ratio, 3.0); //find c5 3 semitones above low A.
    c0 = c5 * pow(0.5, 5.0); //find c0 midinote 0.

    //Find the starting note frequency (starting_midi).
    freq = c0 * pow(ratio, starting_midi);

    for (i = 0; i < notes_per_octave; i++)
    {
	scale[i] = freq; //Store current frequency in array.
	freq *= ratio; //Increase the current frequency to the next note.
    }

    for (i = 0; i < notes_per_octave; i++)
    {
	printf("%d) %lf\n", i + 1, scale[i]);
    }

    return 0;
}
