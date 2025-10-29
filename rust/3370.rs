impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        let mut bits: usize = 0;
        let mut n = n;
        while n > 0 {
            bits += 1;
            n = n >> 1;
        }

        (1 << bits) - 1
    }
}
