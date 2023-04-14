import java.util.Map;
import java.util.HashMap;
import java.util.Scanner;

class words{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        Map<String, Integer> definitions = new HashMap<String, Integer>();
        Map<Integer, String> inverse_definitions = new HashMap<Integer, String>();

        while(sc.hasNext()){
            String command = sc.next();
            if(command.equals("clear")){
                definitions.clear();
                inverse_definitions.clear();
            }else if(command.equals("def")){
                String var;
                int val;
                var = sc.next();
                val = sc.nextInt();
                inverse_definitions.remove(definitions.get(var));
                definitions.put(var, val);
                inverse_definitions.put(val, var);
            }else{
                String line = "";
                String current_command;
                int mode = -1;
                boolean unknown = false;
                int result = 0;
                while(true){
                    current_command = sc.next();
                    line += (" " + current_command);
                    if(current_command.equals("+")){
                        mode = 0;
                    }else if(current_command.equals("-")){
                        mode = 1;
                    }else if(current_command.equals("=")){
                        break;
                    }else if(!definitions.containsKey(current_command)){
                        unknown = true;
                        line += sc.nextLine();
                        break;
                    }else{
                        if(mode == -1){
                            result = definitions.get(current_command);
                        }else if(mode == 0){
                            result += definitions.get(current_command);
                        }else{
                            result -= definitions.get(current_command);
                        }
                    }
                }
                if(!unknown && inverse_definitions.containsKey(result)){
                    System.out.println(line.trim() + " " + inverse_definitions.get(result));
                }else{
                    System.out.println(line.trim() + " " + "unknown");
                }
            }
        }
        sc.close();
    }
}