
class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        //intArrayOf() = 
        var intAnswer = intArrayOf()
        //인덱스와 값을 이용하는 반복문이다. nums.withIndex()를 이용한다.
        for((firstIndex, firstValue) in nums.withIndex()){
            for((secondIndex, secondValue) in nums.withIndex()){
                if(firstValue + secondValue == target && firstIndex != secondIndex){
                    return intArrayOf(firstIndex, secondIndex);
                }
            }
        }
        return intAnswer;
    }
}
fun main(){
}
