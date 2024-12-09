// # ./pipex infile cmd1 cmd2 outfile
// pipe()
//  |
//  |-- fork()
// 	  |
// 	  |-- child // cmd1
// 	  :     |--dup2()
// 	  :     |--close end[0]
// 	  :     |--execve(cmd1)
// 	  :
// 	  |-- parent // cmd2
// 			|--dup2()
// 			|--close end[1]
// 			|--execve(cmd2)
//
//  			 0         |     stdin     |  
// 						   -----------------    
// 				 1         |     stdout    |    
// 						   -----------------    
// 				 2         |     stderr    |  
// 						   -----------------
// 				 3         |     infile    |  // open()
// 						   -----------------
// 				 4         |     outfile   |  // open()
// 						   -----------------
// 				 5         |     end[0]    | 
// 						   -----------------
// 				 6         |     end[1]    |  
// 						   -----------------
