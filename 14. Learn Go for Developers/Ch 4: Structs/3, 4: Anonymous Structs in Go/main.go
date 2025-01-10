myCar := struct {
  brand string
  model string
} {
  brand: "tesla",
  model: "model 3",
}

type car struct {
  brand string
  model string
  doors int
  mileage int
  // wheel is a field containing an anonymous struct
  wheel struct {
    radius int
    material string
  }
}

// Anonymous structs cannot be reused
// They serve kinda the same funcitonality as json or something like this but not only
