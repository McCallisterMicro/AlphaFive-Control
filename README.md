# AlphaFive-Control
A Serial Control Wrapper for the Alpha Clock Five by EvilMadScientist

To create an instance using hardware serial port 0:
AlphaFive FirstClock(&Serial);
Or, to create using a different port: 
AlphaFive SecondClock(&Serial1);

Function descriptions are currently in the .h File.
Currently only works with a single Alpha Clock Five - it does not work with daisy-chained units.
