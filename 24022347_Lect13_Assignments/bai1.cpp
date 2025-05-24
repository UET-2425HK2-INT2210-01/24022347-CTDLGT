
1.   /<[^>]+>/
    <with attribute=”77”>
    </closedtag>
    <and xml tag>

2.  /a.[bc]+/
    abc
    abbbbbbbb
    azc
    abcbcbcbc
    azccbbbbcbccc

3.  /(very )+(fat )?(tall|ugly) man/
    very very fat ugly man
    very very very tall man

4. “abc.def.ghi.jkx”
    regex: ^.{3}\..{3}\..{3}\..{3}$
    - \.: kí tự .
    - .{3}: 11 kí tự bất kì lặp lại 3 lần

5. ^(\([0-9]{3}\)|[0-9]{3})[ .-]?[0-9]{3}[ .-]?[0-9]{4}$
    - (\([0-9]{3}\) | [0-9]{3}): có ngoặc hoặc không có ngoặc
    - [ .-]? 1 trong 3 kí tự trong ngoặc vuông

6. ^(?:[a-zA-Z0-9]+(?:[-_ ]?[a-zA-Z0-9]+)*)?$
    - [a-zA-Z0-9]+: số, chữ, chữa hoa
    - [-_ ]?: có 1 kí tự bất kì trong ngoặc
    - (?:[-_ ]?[a-zA-Z0-9]+)*: không đc lặp lại 2 lần
