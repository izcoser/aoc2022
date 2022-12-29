use std::io;
fn main(){
    let lines = io::stdin().lines();
    let mut max: [i32; 3] = [0; 3];
    let mut cur = 0;
    for line in lines {
        if line.as_ref().unwrap().is_empty(){
            for i in 0..3{
                if cur > max[i]{
                    for k in (1..3 - i).rev(){ // terrible for reading! i just want this: for(int k = 2 - i; k > 0; k--)
                        max[k] = max[k - 1];
                    }
                    max[i] = cur;
                    break;
                }
            } 
            cur = 0;
            continue;
        }
        cur += line.unwrap().parse::<i32>().unwrap();
    }
    println!("{}", max.iter().sum::<i32>());
}
