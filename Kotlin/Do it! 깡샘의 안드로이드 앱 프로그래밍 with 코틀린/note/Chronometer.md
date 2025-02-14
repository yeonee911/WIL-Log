# ✏️Chronometer

🔗 [Chronometer 공식 문서](https://developer.android.com/reference/android/widget/Chronometer)
## ⏰시작 시각 초기화 하는 방법
```
binding.chronometer.base = SystemClock.elapsedRealtime()
```

## 🎸`base`란?
`Chronometer`의 **`base`**는 시작할 때의 기준 시간을 설정하는 값이다.<br>
즉 `base` 값을 설정한 이후 `Chronometer`는 그 `base`에서부터 경과 시간을 계산한다.

## 📜`SystemClock.elapsedRealtime()`란?
`SystemClock.elapsedRealtime()`은 디바이스가 부팅된 후부터 흐른 시간을 반환한다.<br>
예를 들어, 디바이스가 부팅된 후 3초가 지났다면 `SystemClock.elapsedRealtime()`은 3000ms를 반환한다.<br>

## 🤔왜 `base`에 `elapsedRealtime()`을 지정하는가?
✅마치 `영점 조절`이다. 
<br>

`Chronometer`가 `base`를 기준으로 현재 시간에서 그 차이를 계산하여 경과 시간을 화면에 나타내기 때문이다.
즉 `SystemClock.elapsedRealtime() - base`를 계산하여 나타낸다.

따라서 0초부터 시작 시각을 나타내고 싶다면 `base`를 `SystemClock.elapsedRealtime()`값으로 설정해주어야 한다. 