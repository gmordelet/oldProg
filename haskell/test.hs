pack :: Eq a => [a] -> [[a]]
pack [] = []
pack (x : []) = [[x]]
pack x =
     let (xs, acc) = aux x [] 
     in acc : pack xs
     	where
		aux :: Eq a => [a] -> [a] -> ([a], [a])
		aux [] acc = ([], acc)
		aux [x] acc = ([], x : acc)
		aux (x : ys@(y : _)) acc 
		       |x == y = aux ys (x : acc)
		       |otherwise = (ys, (x : acc))		

encode :: Eq a => [a] -> [(Int, a)]
encode [] = []
encode xs = 
       let txs = pack xs 
       in aux txs
       	  where 
	  	aux :: Eq a => [[a]] -> [(Int, a)]
		aux [] = []
		aux (x : xs) = (length x, x !! 0) : aux xs

quicksort :: Ord a => [a] -> [a]
quicksort [] = []
quicksort (x : xs) = 
	  let big = [a | a <- xs, a >= x]
	      small = [a | a <- xs, a < x]
	      in quicksort small ++ [x] ++ quicksort big

fibonacci :: Int -> Int
fibonacci x = case x of 0 -> 0
	      	        1 -> 1
			_ -> fibonacci (x - 1) + fibonacci (x - 2)

fibList :: Int -> [Int]
fibList n = 
	  aux [0, 1] n
	      where aux xs 2 = xs
	      	    aux xs n = aux (add2last xs) (n - 1)
		    	where add2last xs = 
		    	        	  let l = length xs in xs ++ [(xs !! (l - 1) + xs !! (l - 2))]	

cumsum :: Num a => [a] -> [a]
cumsum xs = reverse (aux xs [])
              	    where aux [] acc = acc
		          aux (x : xs) [] = aux xs [x]
			  aux (x : xs) ys = aux xs ((x + head ys) : ys)

dupli list = [[x, x] | x <- list]

dropEvery :: [a] -> Int -> [a]
dropEvery xs n = aux xs n n
	         where aux [] _ _       = []
	       	       aux [x] n 1      = []
		       aux [x] _ _      = [x]
		       aux (x : xs) n c |c == 1    = aux xs n n
		        	      	|otherwise = x : aux xs n (c - 1)