# BF Esoteric Language Interpreter

This language consists of only 8 characters while all whitespace is ignored. The interpreter works on an array of 30,000 bytes.
The pointer begins at index 0 and is moved left or right with '<' or '>' respectivly.

'<'
  Move pointer to the left. If already at begining, move to the end.
  
'>'
  Move pointer to the right. If already at the end, move to the begining.
  
'+'
  Increment the byte under pointer. If value is 255, set to 0.
  
'-' 
  Decrement the byte under pointer. If value is 0, set to 255
  
','
  Input character to fill byte under pointer
  
'.'
  Output the character under the pointer
  
'['
    Enter loop if byte under pointer is greater that zero  
    
']'
    End of loop, continue looping if byte under pointer is greater than zero
  



