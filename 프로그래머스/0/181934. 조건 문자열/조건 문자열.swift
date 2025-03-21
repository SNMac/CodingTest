import Foundation

func solution(_ ineq:String, _ eq:String, _ n:Int, _ m:Int) -> Int {
    switch (ineq, eq) {
        case (">", "="):
            if n >= m {
                return 1
            }
        
        case ("<", "="): 
            if n <= m {
                return 1
            }
        
        case (">", "!"):
            if n > m {
                return 1
            }
        
        case ("<", "!"):
            if n < m {
                return 1
            }
        
        default:
            return 0
    }
    return 0
}