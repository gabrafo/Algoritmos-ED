package leetcode.Palindrome_Number;
class Solution {
    public boolean isPalindrome(int x) {
        String number = String.valueOf(Integer.toUnsignedString(x));
        int numberSize = number.length();
        int normalArray[] = new int[numberSize];
        int reverseArray[] = new int[numberSize];

        for(int i = 0; i<numberSize; i++){
            normalArray[i] = Integer.parseInt(number.substring(i, i+1));
        }

        int index = 0;
        for(int i = numberSize; i>0; i--){
            reverseArray[index] = Integer.parseInt(number.substring(i-1, i));
            index++;
        }

        if(arrayEquals(normalArray, reverseArray)){
            return true;
        }
        return false;
    }

    public boolean arrayEquals(int[] arr1, int[] arr2) {
        if (arr1.length != arr2.length) {
            return false;
        }
        for (int i = 0; i < arr1.length; i++) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
        return true;
    }
}