(set-face-attribute 'default nil :family "DejaVu Sans Mono" :height 170)
(setq inhibit-startup-message t)
(tool-bar-mode -1)
(menu-bar-mode -1)
(scroll-bar-mode -1)
(electric-pair-mode 1)
(setq display-line-numbers-type 'relative)
(global-display-line-numbers-mode t)
(setq-default mode-line-format nil)
(setq initial-scratch-message "")
(setq auto-save-interval 100)
(setq auto-save-timeout  60)
(setq system-time-locale "en_US")
;; Optionally unbind the default shell-command key if desired
(global-unset-key (kbd "M-!"))

;; Bind shell-command to Alt+1 (M-1)
(global-set-key (kbd "M-1") 'shell-command)
;; -----------------------------
;; Indentation Settings
;; -----------------------------
;; Use spaces instead of tabs by default and set tab width to 4.
(setq-default indent-tabs-mode nil)
(setq-default tab-width 4)

;; For C/C++ modes, set a common indentation level.
(add-hook 'c-mode-common-hook
          (lambda ()
            (setq c-basic-offset 4)
            ;; Optionally, adjust other offsets for your style:
            (c-set-offset 'substatement-open 0)))

;; -----------------------------
;; Shift (Indent Rigidly) Functions
;; -----------------------------
(defun my/shift-region-right (start end)
  "Shift the selected region to the right by 4 spaces."
  (interactive "r")
  (indent-rigidly start end 4))

(defun my/shift-region-left (start end)
  "Shift the selected region to the left by 4 spaces."
  (interactive "r")
  (indent-rigidly start end -4))

;; Bind the shift functions to keys for easy use.
(global-set-key (kbd "C-c >") 'my/shift-region-right)
(global-set-key (kbd "C-c <") 'my/shift-region-left)

(defun my/execute-cp-and-open (command)
  "Execute a copy command of the form:
  cp <source> <destination> & open <file>
This function copies <source> to <destination> and then opens <file> in the current buffer."
  (interactive "sEnter command (cp <src> <dest> & open <file>): ")
  (if (string-match "^cp \\([^ ]+\\) \\([^ ]+\\) & open \\(.+\\)$" command)
      (let ((src (match-string 1 command))
            (dest (match-string 2 command))
            (file (match-string 3 command)))
        (shell-command (format "cp %s %s" src dest))
        (find-file file))
    (message "Command doesn't match expected format.")))

;; Bind the function to a key (e.g. C-c c)
(global-set-key (kbd "C-c c") 'my/execute-cp-and-open)


;; Enable ido-mode for a more interactive file selection experience
(ido-mode t)
(ido-everywhere t)

;; Optionally bind C-c o to ido-find-file
(global-set-key (kbd "C-c o") 'ido-find-file)
;; Bind C-c d to open Dired (File Explorer)
(global-set-key (kbd "C-c d") 'dired)

