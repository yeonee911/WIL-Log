# ✏️onTouchEvent()

```
override fun onTouchEvent(event: MotionEvent?): Boolean {
    when (event?.action) {
        MotionEvent.ACTION_DOWN -> {
            Log.d("TAG", "Touch detected!")
            return true
        }
    }
    return super.onTouchEvent(event)
}
```

🤔`action`의 의미? <br>
✅`action`은 `MotionEvent` 클래스의 멤버 변수로, 안드로이드에서 공식적으로 제공
`MotionEvent` 클래스의 `getAction()` 메서드는 **터치 이벤트의 종류를 나타내는 정수 값을 반환**

이 값은 아래와 같은 상수로 정의되어 있음.
- `MotionEvent.ACTION_DOWN` → 손가락을 터치했을 때
- `MotionEvent.ACTION_MOVE` → 손가락을 움직일 때
- `MotionEvent.ACTION_UP` → 손가락을 뗄 때

🔗 [MotionEvent 공식 문서](https://developer.android.com/reference/android/view/MotionEvent)

<br>

🤔`super`의 의미? <br>
✅`super.onTouchEvent(event)`는 **부모 클래스(View)의 기본 터치 처리 로직을 호출**하는 것
- 호출하지 않으면 뷰의 기본 동작(예: 클릭, 스크롤 등)이 작동하지 않을 수 있음
- 특정 이벤트를 직접 처리하면서도, 나머지 이벤트는 부모 클래스의 기본 동작을 유지하려면 `super.onTouchEvent(event)`를 호출해야 함
