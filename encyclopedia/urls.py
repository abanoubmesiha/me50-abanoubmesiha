from django.urls import path

from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path("wiki/<str:title>", views.getEntry, name="view-entry"),
    path("search", views.search, name="search"),
    path("create-entry", views.createEntry, name="create-entry")
]
