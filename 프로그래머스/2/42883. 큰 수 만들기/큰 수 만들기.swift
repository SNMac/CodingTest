import Foundation

func solution(_ number:String, _ k:Int) -> String {
    var stack = [Character]()
    let totalStackLength = number.count - k
    var remainCount = k
    
    for num in number {
        // 스택의 top이 num보다 더 작으면
        // ➡️ 스택이 비어있지 않고
        // ➡️ 스택의 top이 num보다 작고
        // ➡️ 제거할 수 있는 개수가 남아있는 동안
        // 스택의 top을 지워나감(remainCount -= 1)
        while !stack.isEmpty && stack.last! < num && remainCount > 0 {
            stack.removeLast()
            remainCount -= 1
        }
        
        // 스택에 아직 더 담을 수 있는 경우(스택의 길이 < number의 길이에서 k를 뺀 값)
        // 스택에 num을 담음
        if stack.count < totalStackLength {
            stack.append(num)
        }
    }
    
    return String(stack)
}
