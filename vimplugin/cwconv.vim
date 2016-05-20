nnoremap <silent> <F9> :Cwconv<CR>
command! Cwconv :call Cwconverter()

function! Cwconverter()
	if has("win32unix")
		" Overwrite your path here
		:!cygstart ~/projects/cwconv.git/build/main.exe `cat /dev/clipboard`
	elseif has("win32")
		" Not yet
	endif
endfunction
