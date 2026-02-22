import Foundation

func solution(_ bridge_length: Int, _ weight: Int, _ truck_weights: [Int]) -> Int {
    var waitingTrucks: [Int] = truck_weights
    var crossingTrucks: [(truckWeight: Int, elapsed: Int)] = []
    var crossedTrucks: [Int] = []
    var timeElapsed = 0
    
    while crossedTrucks.count != truck_weights.count {
        // 경과 시간 추가
        timeElapsed += 1
        for i in crossingTrucks.indices {
            crossingTrucks[i].elapsed += 1
        }
        
        // 트럭이 다리를 지났는지 확인
        if let first = crossingTrucks.first, first.elapsed == bridge_length {
            crossedTrucks.append(first.truckWeight)
            crossingTrucks.removeFirst()
        }

        // 다리에 트럭이 올라갈 수 있는지 확인
        if crossingTrucks.count < bridge_length {
            let crossingTruckWeights = crossingTrucks.reduce(0, { $0 + $1.truckWeight })
            if crossingTruckWeights < weight {
                if let first = waitingTrucks.first {
                    if crossingTruckWeights + first <= weight {
                    waitingTrucks.removeFirst()
                    crossingTrucks.append((first, 0))
                    }
                }
            }
        }
    }
    
    return timeElapsed
}
