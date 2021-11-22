class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function maxArea($height) {
        $right = count($height)-1;
        $left = 0;
        $h; 
        $distance;
        $sum=0;
        while($left<$right){
            $h = min($height[$left], $height[$right]);
            $distance = $right-$left;
            
            if($h*$distance>$sum){
                $sum = $h*$distance;
            }
            
            if($height[$left]<$height[$right]){
                ++$left;
            }
            else {
                --$right;    
            }
        }
        
        return $sum;
    }
}