class Solution {

    /**
     * @param String[] $strs
     * @return String
     */
    function longestCommonPrefix($strs) {
        $outstr = max($strs);
        
        for($i=0; $i<count($strs); $i++){
           $j=0;
            while($j<strlen($strs[$i])&&$j<strlen($outstr)&&$outstr[$j]==$strs[$i][$j]){
                ++$j;
            }
            if($j==0){
                $outstr="";
                break;
            }
            else $outstr = substr($outstr, 0, $j);
        }
        return $outstr;
    }
}