func isSubsequence(s string, t string) bool {
    var pts int
    if s == "" { return true }
    for ptt := 0; ptt < len(t); ptt++ {
        if t[ptt] == s[pts] { 
            if pts == len(s) - 1 { return true } 
            pts++ 
        }
    }
    return false
}
