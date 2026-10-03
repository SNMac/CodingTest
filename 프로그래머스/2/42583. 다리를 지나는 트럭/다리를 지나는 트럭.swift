import Foundation

func solution(_ bridge_length:Int, _ weight:Int, _ truck_weights:[Int]) -> Int {
    var onBridgeQ: [(Int, Int)] = []  // (truck_weights, onBridgeTime)
    var waitQ: [Int] = truck_weights
    
    var timeElapsed = 1
    onBridgeQ.append((waitQ.first!, 1))
    waitQ.removeFirst()
    
    while !onBridgeQ.isEmpty {
        timeElapsed += 1
        onBridgeQ = onBridgeQ.map { ($0.0, $0.1 + 1) }
        onBridgeQ.removeAll(where: { $0.1 > bridge_length })
        
        if let next = waitQ.first {
            if onBridgeQ.count + 1 <= bridge_length && onBridgeQ.reduce(0, { $0 + $1.0 }) + next <= weight {
                onBridgeQ.append((next, 1))
                waitQ.removeFirst()
            }
        }
    }
    
    return timeElapsed
}
