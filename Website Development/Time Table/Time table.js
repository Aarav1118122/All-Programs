"use strict"
function Timetableapp()
{
	function addTaskElement(taskName)
			{
				var $task = $("#time.table").clone()
				$("button.add", $task).click(function() {
 				$task.add();
 			}
 }