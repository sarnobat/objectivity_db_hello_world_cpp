/**
 * Provides various helper functions
 * @author Asher Moody-Davis
 * 
 */


/*
 * Allows text to be toggled
 */
function toggleMe(a)
{
	var e=document.getElementById(a);
	if(!e)return true;
	if(e.style.display=="none")
	{
		e.style.display="block"
		document.form.button.value = "Hide Solution";
	}
	else
	{
		e.style.display="none"
		document.form.button.value = "View Solution";
	}
	return true;
}