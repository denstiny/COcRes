; 打印 helloworld
(message "hello world")

; 函数
(defun funciton-name(arguments-list)
  "document string"
body)

;; 函数使用
(defun hello-world(name)
  " 输出你的名字 "
  (message name)
  (message "hello %s" name)
  )
;; 使用函数
(hello-world "liming")

;; 声明变量
(setq foo "I\'m foo") ;==> I'm foo
(message foo) ; ==> 打印变量  C-h v 查询变量文档
;; defvar 可以使用文档字符串 , 如果变量存在，则不改变变量的值
(defvar variab "hello world"
  "document string")
variab  ; ==> hello world

;; 作用域
; 局部作用域
(defun circle-area(radix)
  (let ((pi 3.1415926))
    area)
  (setq area (* pi radix radix))
  (message " 直径为 %.2f 面积为 %.2f" radix area))
(circle-area 3)

; 
(defun circle-atea(radix)
  (let * (( pi 3.1415926)
	  (area (* pi radix radix)))
       (message " 直径为 %.2f 的圆周率 %.2f " radix area)))
(circle-atea 3)

(lambda (arguments-list)
  " documentation string"
  body)
(funcall (lambda(name)
	   (message "hello,%s!" name)) "Emacser")
(setq fos(lambda (name)
	   (message "hello , %s!" name)))
(funcall fos "emacs")
