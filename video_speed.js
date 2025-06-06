(() => {
  let vid = document.getElementsByTagName("video")
  console.log(vid)
  for (v of vid) {
    let speed_button = document.createElement("button")
    speed_button.innerHTML = "Press to change speed"
    v.parentElement.appendChild(speed_button)
    speed_button.addEventListener("click", () => {
      let new_speed = prompt("What speed?")
      v.playbackRate = Number.parseFloat(new_speed)
    })
  }
})()
