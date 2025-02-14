package com.example.ch8_event

import android.os.Bundle
import android.os.SystemClock
import android.view.KeyEvent
import android.widget.Toast
import androidx.appcompat.app.AppCompatActivity
import com.example.ch8_event.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    // 뒤로 가기 버튼을 누른 시각을 저장하는 속성
    var initTime = 0L   // Long형 명시적으로 나타냄
                        // Why? elapsedRealtime은 long형을 return

    // 멈춘 시각을 저장하는 속성  (= 현재까지 흐른 시각)
    var pauseTime = 0L

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        // 뷰 바인딩 : XML 파일에 선언한 뷰 객체를 코드에서 쉽게 이용하는 방법
        // viewBinding.isEnabled = true 를 선언해야함
        // activity_main.xml = ActivityMainBinding 클래스 자동 생성
        // inflate() 함수 호출을 통해 바인딩 객체를 얻음
        // 인자로 layoutInflater 전달
        // 액티비티 화면 출력은 setContentView(binding.root)

        val binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)
        binding.startButton.setOnClickListener {
            binding.chronometer.base = SystemClock.elapsedRealtime() + pauseTime
            binding.chronometer.start()

            // 버튼 표시 여부 조정
            binding.startButton.isEnabled = false
            binding.stopButton.isEnabled = true
            binding.resetButton.isEnabled = true
        }

        binding.stopButton.setOnClickListener {
            pauseTime = binding.chronometer.base - SystemClock.elapsedRealtime()
            binding.chronometer.stop()
            binding.startButton.isEnabled = true
            binding.stopButton.isEnabled = false
            binding.resetButton.isEnabled = true
        }

        binding.resetButton.setOnClickListener {
            pauseTime = 0L
            binding.chronometer.base = SystemClock.elapsedRealtime()
            binding.chronometer.stop()
            binding.startButton.isEnabled = true
            binding.stopButton.isEnabled = false
            binding.resetButton.isEnabled = false
        }
    }

    // 뒤로 가기 버튼 이벤트 만들기
    override fun onKeyDown(keyCode: Int, event: KeyEvent?): Boolean {
        // 뒤로 가기 버튼을 눌렀을 때 처리
        if (keyCode === KeyEvent.KEYCODE_BACK) {
            // 뒤로 가기 버튼을 처음 눌렀거나 누른 지 3초가 지났을 때 처리
            if (System.currentTimeMillis() - initTime > 3000) {
                Toast.makeText(
                    this, "종료하려면 한 번 더 누르세요!!",
                    Toast.LENGTH_SHORT
                ).show()
                initTime = System.currentTimeMillis()
                return true
            }
        }
        return super.onKeyDown(keyCode, event)
    }
}