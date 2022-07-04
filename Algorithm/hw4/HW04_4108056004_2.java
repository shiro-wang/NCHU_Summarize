public class HW04_4108056004_2 extends One_0k_rock{
    public HW04_4108056004_2(){
    }

    public boolean[] one0k(String[] str){
        int num = str.length;
        int lengh;
        int mid;
        int tf;
        boolean[] result = new boolean[num];
        
        for(int i=0; i<num; i++){
            lengh = str[i].length();
            if(lengh%2 == 1){
                result[i] = false;
            }else{
                mid = lengh/2;
                tf=1;
                for(int j=0; j<mid; j++){
                    if((str[i].charAt(j) == '1') || (str[i].charAt(j+mid) == '0')){
                        result[i] = false;
                        tf=0;
                        break;
                    }
                }
                if(tf == 1)
                    {result[i] = true;}
            }
        }
        return result;
    }
}