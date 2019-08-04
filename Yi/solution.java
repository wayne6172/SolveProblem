class solution{
    public static void Q1(String text, String target){
        int pos, now = 0;
        while((pos = text.indexOf(target)) != -1){
            System.out.println(pos + now);
            now += pos + 1;
            text = text.substring(pos + 1);
        }
    }
    public static void Q2(String text,String target1, String target2){
        if(text.indexOf(target1) < text.indexOf(target2)){
            System.out.println(
                text.substring(0, text.indexOf(target1)) +
                target2 +
                text.substring(text.indexOf(target1) + target1.length(),text.indexOf(target2)) + 
                target1 +
                text.substring(text.indexOf(target2) + target2.length(), text.length())
            );
        }
        else {
            System.out.println(
                text.substring(0, text.indexOf(target2)) +
                target1 +
                text.substring(text.indexOf(target2) + target2.length(),text.indexOf(target1)) + 
                target2 +
                text.substring(text.indexOf(target1) + target1.length(), text.length())
            );
        }
    }

    public static void transport(int [][] matrix, int [][] matrixT){
        for(int i = 0; i < matrix.length; i++)
            for(int j = 0; j < matrix[i].length; j++)
                matrixT[j][i] = matrix[i][j];

    }
}