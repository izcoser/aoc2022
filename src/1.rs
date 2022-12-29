use std::io;
fn main(){
    let lines = io::stdin().lines();
    let mut max = 0;
    let mut cur = 0;
    for line in lines {
        if line.as_ref().unwrap().is_empty(){
            max = if cur > max { cur } else { max };
            cur = 0;
            continue;
        }
        cur += line.unwrap().parse::<i32>().unwrap();
    }
    println!("{}", max);
}
