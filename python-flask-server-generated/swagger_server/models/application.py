# coding: utf-8

from __future__ import absolute_import
from datetime import date, datetime  # noqa: F401

from typing import List, Dict  # noqa: F401

from swagger_server.models.base_model_ import Model
from swagger_server.models.book_information import BookInformation  # noqa: F401,E501
from swagger_server import util


class Application(Model):
    """NOTE: This class is auto generated by the swagger code generator program.

    Do not edit the class manually.
    """
    def __init__(self, id: str=None, full_name: str=None, application_date: datetime=None, phone: str=None, book_information: BookInformation=None):  # noqa: E501
        """Application - a model defined in Swagger

        :param id: The id of this Application.  # noqa: E501
        :type id: str
        :param full_name: The full_name of this Application.  # noqa: E501
        :type full_name: str
        :param application_date: The application_date of this Application.  # noqa: E501
        :type application_date: datetime
        :param phone: The phone of this Application.  # noqa: E501
        :type phone: str
        :param book_information: The book_information of this Application.  # noqa: E501
        :type book_information: BookInformation
        """
        self.swagger_types = {
            'id': str,
            'full_name': str,
            'application_date': datetime,
            'phone': str,
            'book_information': BookInformation
        }

        self.attribute_map = {
            'id': 'id',
            'full_name': 'fullName',
            'application_date': 'applicationDate',
            'phone': 'phone',
            'book_information': 'bookInformation'
        }
        self._id = id
        self._full_name = full_name
        self._application_date = application_date
        self._phone = phone
        self._book_information = book_information

    @classmethod
    def from_dict(cls, dikt) -> 'Application':
        """Returns the dict as a model

        :param dikt: A dict.
        :type: dict
        :return: The Application of this Application.  # noqa: E501
        :rtype: Application
        """
        return util.deserialize_model(dikt, cls)

    @property
    def id(self) -> str:
        """Gets the id of this Application.


        :return: The id of this Application.
        :rtype: str
        """
        return self._id

    @id.setter
    def id(self, id: str):
        """Sets the id of this Application.


        :param id: The id of this Application.
        :type id: str
        """
        if id is None:
            raise ValueError("Invalid value for `id`, must not be `None`")  # noqa: E501

        self._id = id

    @property
    def full_name(self) -> str:
        """Gets the full_name of this Application.


        :return: The full_name of this Application.
        :rtype: str
        """
        return self._full_name

    @full_name.setter
    def full_name(self, full_name: str):
        """Sets the full_name of this Application.


        :param full_name: The full_name of this Application.
        :type full_name: str
        """
        if full_name is None:
            raise ValueError("Invalid value for `full_name`, must not be `None`")  # noqa: E501

        self._full_name = full_name

    @property
    def application_date(self) -> datetime:
        """Gets the application_date of this Application.


        :return: The application_date of this Application.
        :rtype: datetime
        """
        return self._application_date

    @application_date.setter
    def application_date(self, application_date: datetime):
        """Sets the application_date of this Application.


        :param application_date: The application_date of this Application.
        :type application_date: datetime
        """
        if application_date is None:
            raise ValueError("Invalid value for `application_date`, must not be `None`")  # noqa: E501

        self._application_date = application_date

    @property
    def phone(self) -> str:
        """Gets the phone of this Application.


        :return: The phone of this Application.
        :rtype: str
        """
        return self._phone

    @phone.setter
    def phone(self, phone: str):
        """Sets the phone of this Application.


        :param phone: The phone of this Application.
        :type phone: str
        """
        if phone is None:
            raise ValueError("Invalid value for `phone`, must not be `None`")  # noqa: E501

        self._phone = phone

    @property
    def book_information(self) -> BookInformation:
        """Gets the book_information of this Application.


        :return: The book_information of this Application.
        :rtype: BookInformation
        """
        return self._book_information

    @book_information.setter
    def book_information(self, book_information: BookInformation):
        """Sets the book_information of this Application.


        :param book_information: The book_information of this Application.
        :type book_information: BookInformation
        """
        if book_information is None:
            raise ValueError("Invalid value for `book_information`, must not be `None`")  # noqa: E501

        self._book_information = book_information
