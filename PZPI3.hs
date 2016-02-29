-- 2016-02-29
-- SPOJ PZPI3

main = do
	times <- getLine
	tests $ (read times :: Integer)

tests :: Integer -> IO ()
tests 0 = return ()
tests num = do
	test
	tests $ num - 1

test = do
	line <- getLine
	let 
		(x:y:_) = [read x :: Integer | x <- words line]
	print $ ileZnaczacych x y
	
ileZnaczacych :: Integer -> Integer -> Int
ileZnaczacych l r = length [x |x <- [l..r], isZnaczaca x] 

sqrt' :: Integer -> Integer
sqrt' x = ceiling (sqrt $ fromIntegral x)

dzielniki x = [d | d <- [2..sqrt' x], mod x d == 0]

isZnaczaca :: Integer -> Bool
isZnaczaca x = srednia (dzielniki x) <= (sqrt $ fromIntegral x)

srednia :: [Integer] -> Double
srednia x = (sum x) `div'` (length x)
	where
		div' :: Integer -> Int -> Double
		div' a b = (fromIntegral a :: Double) / (fromIntegral b :: Double)
