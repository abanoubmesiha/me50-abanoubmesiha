from django.urls import include, path
from . import views

urlpatterns = [
    path("", views.index, name="index"),
    path('wiki/<str:title>/', include([
        path('view/', views.getEntry, name="view-entry"),
        path('edit/', views.editEntry, name="edit-entry"),
    ])),
    path("search", views.search, name="search"),
    path("create-entry", views.createEntry, name="create-entry")
]
