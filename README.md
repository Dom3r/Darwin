# Darwin
Program that simulates the evolution of a population of individuals. The population can consist of any
number of individuals. Each individual contains a chromosome, which is a sequence of
natural numbers. Chromosomes can be of different lengths.In each generation k pairs of individuals are drawn, which are then interbred. In this way,
each individual will have a chromosome break at some point. The beginning of one chromosome is joined to the end of another. In other words, individuals exchange pieces of each other's chromosomes. One individual
can be selected for several crosses.
After all crosses have been made, the adaptation of the individuals to the environment is checked.
For this purpose, the value f in [0, 1] of the fitness function is determined for each individual.
Individuals, for which the value of f < w (where w is the extinction threshold), are removed from the
population. Individuals for which f > r (where r is the reproduction threshold) are cloned.
And individuals for which w <= f <= r remain in the population, but do not reproduce.

## The program is run from the command line using the following switches (the order of the switches is arbitrary):
-i input file with the population

-o output file with the population

-w the extinction coefficient in in [0, 1]

-r reproduction rate r in [0, 1]

-p number of generations p

-k number of pairs of individuals to be crossed

-h display of all possible switches and brief instructions

