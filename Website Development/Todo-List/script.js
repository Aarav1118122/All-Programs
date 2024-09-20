/*======================================
=            Variable Block`            =
======================================*/

/*----------  Sidebar Variables  ----------*/

var calendarPage = document.getElementsByClassName("calendar_page")[0];
var todoPage = document.getElementsByClassName("todo_page")[0];
var importantPage = document.getElementsByClassName("important_page")[0];
var completePage = document.getElementsByClassName("completed_page")[0];

/*----------  Todo Page Variables  ----------*/

// Todo Header Variables

var todoPageDate = document.getElementsByClassName("todo_page_date")[0];
var date = new Date();
var month = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
var todoPageDateValue = date.getDate() + "<sup>th</sup> " + month[date.getMonth()] + " " + date.getFullYear();

// List Items Button Variables 

var importantList = document.getElementsByClassName("important_list")[0];
var completedList = document.getElementsByClassName("completed_list")[0];

// Enter Task Variables

var todoList = todoPage.getElementsByClassName("todo_list")[0];
var taskInput = document.getElementsByClassName("task_input")[0];
var todoListItemsNumber = document.getElementsByClassName("todo_list_items_number")[0];
var completedListItemsNumber = document.getElementsByClassName("completed_list_items_number")[0];
var importantListItemsNumber = document.getElementsByClassName("important_list_items_number")[0];
listItemsNumberUpdate();

/*----------  Informationbar Variables  ----------*/
var datePicker = document.querySelector(".date_picker");

/*=====  End of Variable Block`  ======*/

/*=====================================
=            Sidebar Block            =
=====================================*/

function calendarPageButtonClicked() {
	calendarPage.style.display = "flex";
	todoPage.style.display = "none";
	importantPage.style.display = "none";
	completePage.style.display = "none";
}
function todoPageButtonClicked() {
	todoPage.style.display = "block";
	calendarPage.style.display = "none";
	importantPage.style.display = "none";
	completePage.style.display = "none";
}
function importantPageButtonClicked() {
	importantPage.style.display = "block";
	todoPage.style.display = "none";
	calendarPage.style.display = "none";
	completePage.style.display = "none";
}
function completedPageButtonClicked() {
	completePage.style.display = "block";
	todoPage.style.display = "none";
	calendarPage.style.display = "none";
	importantPage.style.display = "none";
}
function listItemsNumberUpdate() {
	todoListItemsNumber.innerHTML = todoList.childElementCount;
	completedListItemsNumber.innerHTML = completedList.childElementCount;
	importantListItemsNumber.innerHTML = importantList.childElementCount;
}

/*=====  End of Sidebar Block  ======*/

/*=================================================
=            Todo Page Block           =
=================================================*/

/*----------  Todo Header Sublock  ----------*/

todoPageDate.innerHTML = todoPageDateValue;
function deleteListItemsButtonClicked() {
	if (event.target.className == "deleteListItemsButtonClicked") {
		event.target.parentElement.parentElement.querySelector(".todo_list").innerHTML = "";
	}
	if (event.target.className == "fa fa-trash-o") {
		event.target.parentElement.parentElement.parentElement.querySelector(".todo_list").innerHTML = "";
	}
	listItemsNumberUpdate();
}

/*----------  List Item Buttons Sublock  ----------*/

function completeButtonClicked() {
	event.target.classList.toggle("complete_button_on");
	if (event.target.parentElement.parentElement.className == "todo_todo_list todo_list") {
		completedList.appendChild(event.target.parentElement);
	}
	else if (event.target.parentElement.parentElement.className == "completed_list todo_list") {
		todoList.appendChild(event.target.parentElement);
	}
	listItemsNumberUpdate();
}
function importantButtonClicked() {
	event.target.classList.toggle("important_button_on");
	if (event.target.parentElement.parentElement.className == "todo_todo_list todo_list") {
		importantList.appendChild(event.target.parentElement);
	}
	else if (event.target.parentElement.parentElement.className == "important_list todo_list") {
		todoList.appendChild(event.target.parentElement);
	}
	listItemsNumberUpdate();
}
function deleteButtonClicked() {
	if (event.target.className == "delete_button") {
		event.target.parentElement.remove();
	}
	if (event.target.className == "fa fa-trash-o") {
		event.target.parentElement.parentElement.remove();
	}
	listItemsNumberUpdate();
}

/*----------  Enter Task Sublock  ----------*/

function taskInputButtonClicked() {
	if (taskInput.value != "") {
		var todoListItems = document.createElement("li");
		todoListItems.className += "todo_list_items";
		todoListItems.innerHTML =
			`
		<button class="complete_button_off" id="complete_button" onclick="completeButtonClicked()">&#10004</button>
		<input type="text" class="task_name" value="${taskInput.value}">
		<button class="important_button_off" id="important_button" onclick="importantButtonClicked()">&#9733</button>
		<button class="delete_button" id="delete_button" onclick="deleteButtonClicked()"><i class="fa fa-trash-o"></i></button>
		<button class="more_button" onclick="more_button_clicked()">&#9002</button>
		`;
	}
	todoList.appendChild(todoListItems);
	taskInput.value = "";
	taskInput.focus();
	listItemsNumberUpdate();
};
function enterKeyPressed() {
	if (event.keyCode == 13) {
		if (taskInput.value != "") {
			var todoListItems = document.createElement("li");
			todoListItems.className += "todo_list_items";
			todoListItems.innerHTML =
				`
			<button class="complete_button_off" id="complete_button" onclick="completeButtonClicked()">&#10004</button>
			<input type="text" class="task_name" value="${taskInput.value}">
			<button class="important_button_off" id="important_button" onclick="importantButtonClicked()">&#9733</button>
			<button class="delete_button" id="delete_button" onclick="deleteButtonClicked()"><i class="fa fa-trash-o"></i></button>
			<button class="more_button" onclick="more_button_clicked()">&#9002</button>
			`;
		}
		todoList.appendChild(todoListItems);
		taskInput.value = "";
		taskInput.focus();
		listItemsNumberUpdate();
	}
}
function more_button_clicked() {
	var informationbar = document.getElementsByClassName("informationbar")[0].style.display = "block";
}
/*=====  End Todo Page Block  ======*/

/*==============================================
=            Informationbar Section            =
==============================================*/

function showDatePicker() {
	datePicker.style.display = "block";
	datePicker.style.top = event.target.style.padding + "px";
}

/*=====  End of Informationbar Section  ======*/
