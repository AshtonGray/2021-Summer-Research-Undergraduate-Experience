# Summer-2021-Research-Undergraduate-Experience
Here, there are three different allocation C programs, where dynamic memory would be allocated in different magnitudes and frequencies.
The allocation information including time and size are saved in their respective "xAllocationData.txt" files

The bash file "research.sh" would then be used to track the processes total memory used, and this time and 
size data is stored in their respective "xAllocationTotalMem.txt" files

This information was then fed into an RNN, to recognize the pattern, and be able to predict if there was an attack if it deviated from the set pattern.
